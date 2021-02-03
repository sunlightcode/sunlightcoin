from distutils.core import setup
setup(name='STCspendfrom',
      version='1.0',
      description='Command-line utility for sunlightcoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@sunlightcoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
