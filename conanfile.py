from conan import ConanFile
from conan.tools.meson import Meson, MesonToolchain
from conan.tools.gnu import PkgConfigDeps


class FsmDriverC(ConanFile):
    name = "FSM Driver Test"
    version = "0.1"
    description = ""
    author = "Nicholas H.R. Sims (nickhrsims@gmail.com)"

    settings = "os", "arch", "compiler", "build_type"
    requires = (
        "log.c/cci.20200620",
        "clove-unit/2.4.1",
    )

    options = {"shared": [True, False]}
    default_options = {"shared": False}

    def generate(self):
        pkgconfig = PkgConfigDeps(self)
        toolchain = MesonToolchain(self)

        pkgconfig.generate()
        toolchain.generate()

    def build(self):
        meson = Meson(self)
        meson.configure()
        meson.build()

    def package(self):
        meson = Meson(self)
        meson.install()
