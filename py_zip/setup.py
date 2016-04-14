#!/usr/bin/env python

from distutils.core import setup, Extension
 
__version__ = "0.1"
 
macros = [('MODULE_VERSION', '"%s"' % __version__)]
 
setup(name         = "py-zip",
      version      = __version__,
      author       = "Wei Liu",
      author_email = "wei_liu@intsig.net",
      url          = "",
      download_url = "",
      description  = "XOR encrypt/decrypt for Python",
      long_description = "",
      license      = "LGPL",
      platforms    = ["Platform Independent"],
      classifiers  = [
        "Development Status :: 5 - Production/Stable",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: GNU Library or Lesser General Public License (LGPL)",
        "Operating System :: OS Independent",
        "Programming Language :: Python",
        "Topic :: Software Development :: Libraries :: Python Modules"
      ],
      ext_modules  = [
        Extension(name='py_zip', sources=['py_zip.c','zip.c'], define_macros=macros, extra_compile_args=['-shared','-L/usr/local/lib/','-I/usr/local/include/'])
      ]
)
