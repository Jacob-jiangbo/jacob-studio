# comments omitted
die() {
        bbfatal "$*"
}

bbnote() {
        echo "NOTE:" "$*"
}

bbwarn() {
        echo "WARNING:" "$*"
}

bbfatal() {
        echo "FATAL:" "$*"
        exit 1
}

addtask showdata
do_showdata[nostamp] = "1"
python do_showdata() {
        import sys
        # emit variables and shell functions
        bb.data.emit_env(sys.__stdout__, d, True)
        # emit the metadata which isnt valid shell
        for e in bb.data.keys(d):
                if bb.data.getVarFlag(e, 'python', d):
                        sys.__stdout__.write("\npython %s () {\n%s}\n" %
(e, bb.data.getVar(e, d, 1)))
}

addtask listtasks
do_listtasks[nostamp] = "1"
python do_listtasks() {
        import sys
        for e in bb.data.keys(d):
                if bb.data.getVarFlag(e, 'task', d):
                        sys.__stdout__.write("%s\n" % e)
}

addtask build
do_build[dirs] = "${TOPDIR}"
do_build[nostamp] = "1"
python base_do_build () {
        bb.note("The included, default BB base.bbclass does not define a useful default task.")
        bb.note("Try running the 'listtasks' task against a .bb to see what tasks are defined.")
}

EXPORT_FUNCTIONS do_clean do_mrproper do_build

