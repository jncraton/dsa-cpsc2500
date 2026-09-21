%: %.cc
	g++ -std=c++23 $< -o $@
	./$@

format:
	clang-format -i *.cc

clean:
	find . -maxdepth 1 -type f ! -name '*.*' ! -name 'makefile' -delete