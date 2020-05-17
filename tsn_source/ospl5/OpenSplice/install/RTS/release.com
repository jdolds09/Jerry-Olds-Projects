echo "<<< OpenSplice RTS Release  For  Date  >>>"
if [ "$SPLICE_ORB" = "" ]
then
    SPLICE_ORB=DDS_OpenFusion_1_6_1
    export SPLICE_ORB
fi
if [ "$SPLICE_JDK" = "" ]
then
    SPLICE_JDK=jdk
    export SPLICE_JDK
fi
OSPL_HOME="@@INSTALLDIR@@/RTS/"
OSPL_TARGET=
PATH=$OSPL_HOME/bin:$PATH
LD_LIBRARY_PATH=$OSPL_HOME/lib:$LD_LIBRARY_PATH
OSPL_URI=file://$OSPL_HOME/etc/config/ospl.xml
. $OSPL_HOME/etc/java/defs.$SPLICE_JDK
export CLASSPATH OSPL_HOME OSPL_TARGET PATH LD_LIBRARY_PATH OSPL_URI
$@
