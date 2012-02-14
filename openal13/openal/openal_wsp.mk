.PHONY: clean All

All:
	@echo ----------Building project:[ openal - Debug ]----------
	@"mingw32-make.exe"  -j 4 -f "openal.mk"
clean:
	@echo ----------Cleaning project:[ openal - Debug ]----------
	@"mingw32-make.exe"  -j 4 -f "openal.mk" clean
