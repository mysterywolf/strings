from building import *
Import('rtconfig')

src	= Glob('*.c')
cwd = GetCurrentDir()
path = [cwd]
group = []

if rtconfig.PLATFORM != 'gcc':
    group = DefineGroup('POSIX', src, depend = ['PKG_USING_POSIX_STRINGS'], CPPPATH = path)

Return('group')
