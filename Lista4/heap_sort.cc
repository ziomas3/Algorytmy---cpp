void
przesiej (int i, int n, double t[])
{
  int k;
  double x;
  while (true)
    {
      k = 2 * i + 2;
      if (
	  (k < n && t[k] > t[i] && t[k] > t[k - 1])
	  || 
	  (--k < n && t[k] > t[i]))
	{
	  x = t[k];
	  t[k] = t[i];
	  t[i] = x;
	  i = k;
	}
      else
	return;
    }
}

// Szybsza (o ok 10%) wersja funkcji  przesiej
void
przesiej2 (int i, int n, double t[])
{
  int k;
  double x = t[i]; //przesiewany element
  while (true)
    {
      k = 2 * i + 2;//prawy syn 'x'-a
      if (
          (k < n && t[k] > x && t[k] > t[k - 1]) 
          ||
	  (--k < n && t[k] > x)
	 )
	{
	  t[i] = t[k];
	    i  =   k;
	}
      else
	{
	  t[i] = x;
	  return;
	}
    }
}


void
heap_sort (int n, double t[])
{
  int i;
  // Budowanie stogu
  for (i = n / 2; i >= 0; i--)
    przesiej2 (i, n, t);
  // Opró¿nianie stogu
  for (i = n - 1; i > 0; i--)
    {
      double x = t[i]; t[i] = t[0]; t[0] = x; // Zamieñ t[0] z t[i]
      przesiej2 (0, i, t);
    }
}
