from building import *
Import('rtconfig')

src	= Glob('*.c')
cwd = GetCurrentDir()
path = [cwd]
group = []

group = DefineGroup('POSIX', src, depend = ['PKG_USING_POSIX_STRINGS'], CPPPATH = path)

Return('group')
