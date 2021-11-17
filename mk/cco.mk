cproc =
clang = -Oz -fno-signed-zeros -freciprocal-math -ffp-contract=fast -fno-trapping-math\
-ffinite-math-only -ffast-math
gcc = -fgcse-after-reload -fpeel-loops -funswitch-loops -fipa-cp-clone -fpredictive-commoning\
-fvect-cost-model=dynamic -fversion-loops-for-strides -fallow-store-data-races -ffast-math\
$(FLOOP) $(FSPLIT) $(FTREE)
FLOOP = -floop-interchange -floop-unroll-and-jam
FSPLIT = -fsplit-loops -fsplit-paths
FTREE = -ftree-loop-distribution -ftree-partial-pre