from setuptools import setup, Extension

def main():
    setup(name="cutils",
          version="1.0.1",
          author="Anton Kukhtichev",
          ext_modules=[Extension("cutils", ["cutils.cpp"])]
    )

if __name__ == "__main__":
    main()
