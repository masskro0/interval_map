#ifndef INTERVAL_MAP_INCLUDE_INTERVALMAP_HPP_
#define INTERVAL_MAP_INCLUDE_INTERVALMAP_HPP_

#include <limits>
#include <map>

template<typename K, typename V>
class IntervalMap {
private:
  friend void IntervalMapTest();
  V val_begin_;
  std::map<K, V> map_;

public:
  // Assign whole range to val.
  explicit IntervalMap(V const& val)
    : val_begin_(val)
  {}

  // Assign value val to interval [keyBegin, keyEnd).
  void assign( K const& keyBegin, K const& keyEnd, V const& val)
  {
    // Wrong interval.
    if (!(keyBegin < keyEnd)) {
      return;
    }

    // Insert initial entry.
    if (map_.empty()) {
      map_.insert(std::make_pair(std::numeric_limits<K>::lowest(), val_begin_));
    }

    // Inserting an element as the first entry which has the same value as the initial value is
    // not allowed.
    if (map_.lower_bound(keyBegin) == map_.begin() && val == map_.begin()->second) {
      return;
    }

    // Delete all elements in the interval.
    V value_saved = (--map_.lower_bound(keyEnd))->second;
    auto it_interval = map_.lower_bound(keyBegin);
    while (it_interval != map_.end() && it_interval->first < keyEnd) {
      map_.erase(it_interval++);
    }

    map_.insert(it_interval, std::make_pair(keyBegin, val));

    // Fill up the interval [keyEnd, keyBeginNextElement] with the overwritten value.
    auto it_next = map_.upper_bound(keyEnd);
    if (!(it_next->first - 1 < keyEnd)) {
      map_.insert(--it_next, std::make_pair(keyEnd, value_saved));
    }

    // Make sure to add the default value as an new entry at the end.
    auto it_end = --map_.end();
    if (it_end->second != val_begin_) {
      map_.insert(it_end, std::make_pair(keyEnd, val_begin_));
    }
  }

  V const& operator[](K const& key) const
  {
    auto it = map_.upper_bound(key);
    if (it == map_.begin()) {
      return val_begin_;
    } else {
      return (--it)->second;
    }
  }
};

#endif //INTERVAL_MAP_INCLUDE_INTERVALMAP_HPP_
