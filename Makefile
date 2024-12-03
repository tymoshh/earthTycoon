compile:
	g++ -Iinclude -Ilib -Iinclude/SDL2 -Isrc -Llib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
run:
	./a.out
	
pull:
	git pull origin main --allow-unrelated-histories
	make end
commit:
	git add .
	git commit -m "Normal commit"
	make end
push:
	make pull
	git push -u origin main
	make end

end:
	cls