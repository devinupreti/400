all : devin

devin : dupreti_agency.o dupreti_player.o dupreti_team.o
		g++ dupreti_agency.o dupreti_player.o dupreti_team.o -o devin
		
dupreti_agency.o : dupreti_agency.cc
				   g++ -c dupreti_agency.cc
				   
dupreti_player.o : dupreti_player.cc
				   g++ -c dupreti_player.cc
				   
dupreti_team.o : dupreti_team.cc
				 g++ -c dupreti_team.cc

