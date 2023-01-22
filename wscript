from waflib.Tools import waf_unit_test


def options(opt):
    opt.load('compiler_c waf_unit_test')


def configure(cfg):
    cfg.load('compiler_c waf_unit_test')


def build(bld):
    bld.stlib(includes='inc', export_includes='inc',
              source='src/hand_side.c', target='hand_side')
    bld.program(features='c cprogram test',
                source='tests/test1.c', target='test1', use='hand_side')
    bld.add_post_fun(waf_unit_test.summary)
