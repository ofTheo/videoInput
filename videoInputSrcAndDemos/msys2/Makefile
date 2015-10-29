all: ../../compiledLib/msys2/libvideoinput.a

../libs/videoInput/videoInput.o: ../libs/videoInput/videoInput.cpp Makefile
	@g++ -c $< -o "$@" -O3 -I../libs/videoInput/

../../compiledLib/msys2/libvideoinput.a: ../libs/videoInput/videoInput.o
	@mkdir -p ../../compiledLib/msys2
	@ar -cr "$@" $<
	
.PHONY: clean

clean:
	@rm -f ../../compiledLib/msys2/libvideoinput.a
	@rm -f ../libs/videoInput/videoInput.o
	
