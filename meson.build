project('fsm', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

cc = meson.get_compiler('c')
cmath = cc.find_library('m', required : false)

logc = dependency('log.c', version : 'cci.20200620')
cloveunit = dependency('clove-unit', version : '2.4.1')

exe = executable('fsm',
                 'main.c',
                 'fsm.c',
                 install : false,
                 dependencies : [logc, cloveunit, cmath],
                )
