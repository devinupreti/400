all : devin

devin : dupreti_cal.o dupreti_op.o
	g++ dupreti_cal.o dupreti_op.o -o devin

dupreti_cal.o : dupreti_cal.cc
		g++ -c dupreti_cal.cc

dupreti_op.o : dupreti_op.cc
		g++ -c dupreti_op.cc

