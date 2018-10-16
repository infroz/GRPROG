int intLength(int a) {
	// Absoluttverdi
	if (a < 0) {
		a = a * -1;
	}
	int i = a, length = 1, tiTall = 10;
	while (!(i < tiTall)) {
		tiTall += tiTall * 10;
		length += 1;
	}
	return length;
}