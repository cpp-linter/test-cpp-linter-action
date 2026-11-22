static auto fixits(int x, const int *p) -> int {
  if (p == nullptr) {
    return 0;
  }
  if (x > 1) {
    return 1;
  }
  return 2;
}
