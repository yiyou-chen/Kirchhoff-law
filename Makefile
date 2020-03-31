build:
	g++ Kirchhoff.cpp -g -o Kirchhoff
run: build
	./Kirchhoff
clean:
	rm -rf Kirchhoff *.tar.gz
dist:
	tar -zcvf Kirchhoff.tar.gz Kirchhoff.cpp Makefile README 
