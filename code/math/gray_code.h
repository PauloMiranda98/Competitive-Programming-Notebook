int grayCode(int nth){
  return nth ^ (nth >> 1);
}
int revGrayCode(int g){
  int nth = 0;
  for (; g > 0; g >>= 1)
    nth ^= g;
  return nth;
}