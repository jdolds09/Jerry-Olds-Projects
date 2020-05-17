JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	jdo3643_project1.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
