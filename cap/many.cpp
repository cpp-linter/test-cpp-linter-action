// Many clang-tidy findings of one level (rs#583 annotation cap test)
int many(int x) {
  int total = 0;
  if (x > 0)
    total += 0;
  if (x > 1)
    total += 1;
  if (x > 2)
    total += 2;
  if (x > 3)
    total += 3;
  if (x > 4)
    total += 4;
  if (x > 5)
    total += 5;
  if (x > 6)
    total += 6;
  if (x > 7)
    total += 7;
  if (x > 8)
    total += 8;
  if (x > 9)
    total += 9;
  if (x > 10)
    total += 10;
  if (x > 11)
    total += 11;
  if (x > 12)
    total += 12;
  if (x > 13)
    total += 13;
  if (x > 14)
    total += 14;
  return total;
}
