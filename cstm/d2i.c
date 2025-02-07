int  d2i(double x)
{
  int  y;

  y = (int)x;
  if ((double)y != x)
    y = (int)(x + 1e-10);
  return (y);
}
