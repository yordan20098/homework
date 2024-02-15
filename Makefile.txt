all: safeadd safesubtract safemultiply safedivide

safeadd: safeadd.c safeint.c util.c
    gcc -o safeadd safeadd.c safeint.c util.c

safesubtract: safesubtract.c safeint.c util.c
    gcc -o safesubtract safesubtract.c safeint.c util.c

safemultiply: safemultiply.c safeint.c util.c
    gcc -o safemultiply safemultiply.c safeint.c util.c

safedivide: safedivide.c safeint.c util.c
    gcc -o safedivide safedivide.c safeint.c util.c

clean:
    rm -f safeadd safesubtract safemultiply safedivide
