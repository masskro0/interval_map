# Interval Map
```IntervalMap<K, V>``` is a data structure that efficiently associates intervals of keys of type K
with values of type V. It is implemented on top of std::map. It's a single header file only and only
depends on the standard library, so you can include it directly to your project.<br><br>
```main.cpp``` includes example usage and unit tests.

### Example
The std::map (0,'A'), (3,'B'), (5,'A') represents the mapping:

* ...
* 0 -> 'A'
* 1 -> 'A'
* 2 -> 'A'
* 3 -> 'B'
* 4 -> 'B'
* 5 -> 'A'
* 6 -> 'A'
* 7 -> 'A'
* ...

The interval map is canonical, meaning that consecutive entries must not have the same value.