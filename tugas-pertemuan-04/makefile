PROBLEMS	:= problem_a

PROB_OBJS	:= $(patsubst %, %.o, $(PROBLEMS))
PROB_SRCS	:= $(patsubst %, %.cpp, $(PROBLEMS))
PROB_HDRS	:= $(patsubst %, %.hpp, $(PROBLEMS))

OUT	:= tugas
OBJS	:= main.o $(PROB_OBJS)
SOURCE	:= main.cpp $(PROB_SRCS)
HEADER	:= $(PROB_HDRS)

OUT_TEST	:= tugas_test
OBJS_TEST	:= main_test.o $(PROB_OBJS)
SOURCE_TEST	:= main_test.cpp $(PROB_SRCS)
HEADER_TEST	:= $(PROB_HDRS)

CXX	:= g++
FLAGS	:= -c -Wall -Wpedantic -std=c++14 $(extra_flags)
LFLAGS	:= -Wall -std=c++14 $(extra_lflags)

.PHONY: all
.DELETE_ON_ERROR:
all: $(OUT) $(OUT_TEST)

$(OUT): $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(OUT)

$(OUT_TEST): $(OBJS_TEST)
	$(CXX) $(LFLAGS) $(OBJS_TEST) -o $(OUT_TEST)

main.o: main.cpp
	$(CXX) $(FLAGS) main.cpp

main_test.o: main_test.cpp
	$(CXX) $(FLAGS) main_test.cpp

$(PROB_OBJS): $(PROB_SRCS)
	$(CXX) $(FLAGS) $< -o $@


.PHONY: run
run: $(OUT)
	./$(OUT)

.PHONY: test
test: $(OUT_TEST)
	./$(OUT_TEST) $(spec)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_TEST) $(OUT) $(OUT_TEST)
