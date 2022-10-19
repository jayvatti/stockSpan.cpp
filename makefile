StockSpan.o: StockSpan.cpp StockSpan.h
        g++ -c StockSpan.cpp

main.o: main.cpp StockSpan.h
        g++ -c main.cpp

runStockSpan: StockSpan.o main.o
        g++ StockSpan.o main.o -o runStockSpan

clean:
        rm -f *.o
        rm runStockSpan
run: runStockSpan
        ./runStockSpan
