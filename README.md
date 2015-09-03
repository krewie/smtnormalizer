#SMT normalizer
Satisfiability modulo theories (SMT) is about determining the satisfiability of logical formulas over a range of one or more theories. SMT solvers are programs that are designed
to determine the satisfiability of logical formulas and to and a satisfying model. Since the
SMT problem is known to be NP-complete, the SMT initiative holds annual competitions
to further advance and stimulate the techniques and tools used by the SMT community.

To prevent unfair entries to the competition, a benchmark scrambler with a random seed
is used to rename variables, randomly permutes arguments and hides benchmark names
for each of the formulas. This paper is about researching the possibility of proving sat-
isfiability of expressions that are semantically equal but not necessarily syntactical. The
purpose of this project was to develop a computer program that is able to normalize
benchmark scripts to a standard defined format such that by scrambling syntactically
equal scripts would result in the same result when normalized. 
The implementation that

was conceived is incomplete and inefficient for larger SMT scripts in terms of 
computational complexity due to time constraints. The implementation that was conceived is
incomplete and inefficient for larger SMT scripts in terms of computational complexity
due to time constraints however, the research of that was conceived during this thesis
provide an interesting insight in the complexity of normalizing benchmark scripts and its
relation the graph isomorphism.
