get-deps:
	pwd
	mkdir make
	cd make
	cmake  -G "Unix Makefiles" ../
	pwd
	cd..