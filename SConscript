from building import *

src = ['strings.c']
cwd = GetCurrentDir()
path = [cwd]
group = []

group = DefineGroup('POSIX', src, depend = ['PKG_USING_POSIX_STRINGS'], CPPPATH = path)

Return('group')
