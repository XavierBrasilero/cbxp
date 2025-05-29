ARTIFACTS	= ${PWD}/artifacts
DIST		= ${PWD}/dist

CXX			= ibm-clang++64
CFLAGS		= \
			-fzos-le-char-mode=ascii \
			-I /usr/include/zos \
			-Wno-trigraphs

all: psa ecvt

mkdirs:
	@mkdir $(ARTIFACTS)
	@mkdir $(DIST)

psa: clean mkdirs
	$(CXX) $(CFLAGS) -o $(DIST)/psa psa.cpp
	$(DIST)/psa

ecvt: clean mkdirs
	$(CXX) $(CFLAGS) -o $(DIST)/ecvt ecvt.cpp
	$(DIST)/ecvt

clean:
	@rm -rf $(ARTIFACTS) $(DIST)
