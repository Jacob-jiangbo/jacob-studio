DESCRIPTION = "Recipe to build the 'nano' editor"

PN = "nano"
PV = "2.2.6"

SRC_URI = "http://www.nano-editor.org/dist/v2.2/nano-2.2.6.tar.gz"

python do_fetch() {
   bb.note("Downloading source tarball from ${SRC_URI} ...")

   src_uri = (bb.data.getVar('SRC_URI', d, True) or "").split()
   if len(src_uri) == 0:
      bb.fatal("Empty URI")

      bb.fetch.init(src_uri, d)
      bb.fetch.go(d)

   bb.note("Download successful.")
}

addtask fetch before do_build


python do_unpack() {
   bb.note("Unpacking source tarball ...")

   os.system("tar x -C ${WORKDIR} -f ${DL_DIR}/${P}.tar.gz")

   bb.note("Unpacked source tarball.")
}

addtask unpack before do_build after do_fetch


python do_configure() {
   bb.note("Configuring source package ...")

   os.system("cd ${WORKDIR}/${P} && ./configure")

   bb.note("Configured source package.")
}

addtask configure before do_build after do_unpack


python do_compile() {
   bb.note("Compiling package...")

   os.system("cd ${WORKDIR}/${P} && make")

   bb.note("Compiled package.")
}

addtask compile before do_build after do_configure

