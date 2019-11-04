all: mst/main select/main

mst/main: mst/mst.cpp
	g++ -g mst/mst.cpp -o mst/main -std=c++03 -O2 -w 

select/main: select/select.cpp
	g++ -g select/select.cpp -o select/main -std=c++03 -O2 -w

clean:
	rm -f select/*~ mst/*~
