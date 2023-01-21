def options(opt):
    opt.load('compiler_c')

def configure(cfg):
    cfg.load('compiler_c')

def build(bld):
    bld.stlib(includes='inc', source='src/hand_side.c', target='hand_side')
