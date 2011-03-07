env = Environment(CPPPATH = ['.'])
libs = [
    'Irrlicht',
    'BulletDynamics',
    'BulletCollision',
    'LinearMath',
    ]

files = Glob('*cpp');

env.Program(
    'myprogram',
    files,
    LIBS=libs
    )
Repository('/usr/include/bullet/')
