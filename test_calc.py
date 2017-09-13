import unittest
import datetime
import ctypes
import calc

def now():
    return datetime.datetime.now()

def deltasec(t0, t1):
    delta = t1 - t0
    return delta.total_seconds()

class TestCalc(unittest.TestCase):

    def test_hex2dec_valid(self):
        self.assertEqual(0x0000, calc.hex2dec('0'))
        self.assertEqual(0x0001, calc.hex2dec('1'))
        self.assertEqual(0x1234, calc.hex2dec('1234'))
        self.assertEqual(0x000a, calc.hex2dec('a'))

    def test_hex2dec_invalid(self):
        self.assertEqual(0, calc.hex2dec('n'))

    def test_hex2dec_time(self):
        bufs = ''.join(['%02X' % (i & 0xff) for i in range(2048)])
        n = 4096

        # built-in hex2dec
        t0 = now()
        for i in range(n):
            [int(bufs[i:i+1], 16) for i in range(0, len(bufs), 2)]
        t1 = now()
        t_builtin = deltasec(t0, t1)

        # c-extension hex2dec
        t0 = now()
        for i in range(n):
            [calc.hex2dec(bufs[i:i+1]) for i in range(0, len(bufs), 2)]
        t1 = now()
        t_extend1 = deltasec(t0, t1)

        # c-extension hex2decs
        t0 = now()
        for i in range(n):
            decs = calc.hex2decs(bufs, 2048)
        t1 = now()
        t_extend2 = deltasec(t0, t1)

        #self.assertGreaterEqual(t_builtin, t_extend1)
        print '%.4f %.4f %.4f' % (t_builtin, t_extend1, t_extend2)
        print len(decs)

if (__name__ == '__main__'):
    unittest.main()
