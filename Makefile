get-deps:
	mkdir make
	cd make
	cmake  -G "MinGW Makefiles" ../
	cd..