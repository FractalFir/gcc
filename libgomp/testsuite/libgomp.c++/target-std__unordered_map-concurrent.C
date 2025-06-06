// { dg-do run }
// { dg-additional-options -DMEM_SHARED { target offload_device_shared_as } }

#include <stdlib.h>
#include <time.h>
#include <set>
#include <unordered_map>

#define N 3000

void init (int data[], bool unique)
{
  std::set<int> _set;
  for (int i = 0; i < N; ++i)
    {
      // Avoid duplicates in data array if unique is true.
      do
	data[i] = rand ();
      while (unique && _set.count (data[i]) > 0);
      _set.insert (data[i]);
    }
}

bool validate (long long sum, int keys[], int data[])
{
  long long total = 0;
  for (int i = 0; i < N; ++i)
    total += (long long) keys[i] * data[i];
  return sum == total;
}

int main (void)
{
  int keys[N], data[N];
  std::unordered_map<int,int> _map;

  srand (time (NULL));
  init (keys, true);
  init (data, false);

  #pragma omp target enter data map (to: keys[:N], data[:N]) map (alloc: _map)

  #pragma omp target
    {
#ifndef MEM_SHARED
      new (&_map) std::unordered_map<int,int> ();
#endif
      for (int i = 0; i < N; ++i)
	_map[keys[i]] = data[i];
    }

  long long sum = 0;
  #pragma omp target teams distribute parallel for reduction (+:sum)
    for (int i = 0; i < N; ++i)
      sum += (long long) keys[i] * _map[keys[i]];

#ifndef MEM_SHARED
  #pragma omp target
    _map.~unordered_map ();
#endif

  #pragma omp target exit data map (release: _map)

  bool ok = validate (sum, keys, data);
  return ok ? 0 : 1;
}
