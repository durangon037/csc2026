#include "TrackReconstructor.hpp"
#include <algorithm>

namespace csc2026 {

TrackReconstructor::TrackReconstructor(double minPt) : m_minPt(minPt) {}

void TrackReconstructor::addHit(const Hit& hit) { m_hits.push_back(hit); }

std::vector<Track> TrackReconstructor::reconstruct() const {
    std::vector<Track> tracks;
    if (m_hits.empty()) {
        return tracks;
    }

    // Dummy reconstruction: one track containing all hits
    Track t;
    t.hits = m_hits;

    // Fake pT estimate
    t.pt = 0.0;
    for (const auto& h : m_hits) {
        t.pt += h.energy;
    }

    if (t.pt >= m_minPt) {
        tracks.push_back(t);
        m_bestTrack = t;
    }

    return tracks;
}

const Track* TrackReconstructor::getBestTrack() const {
    return &m_bestTrack;
}

} // namespace csc2026

