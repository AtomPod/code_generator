INCLUDEPATH += $$PWD/include

HEADERS += $$PWD/include/fmt/format.h \
  $$PWD/include/fmt/args.h \
  $$PWD/include/fmt/chrono.h \
  $$PWD/include/fmt/color.h \
  $$PWD/include/fmt/compile.h \
  $$PWD/include/fmt/core.h \
  $$PWD/include/fmt/format-inl.h \
  $$PWD/include/fmt/locale.h \
  $$PWD/include/fmt/os.h \
  $$PWD/include/fmt/ostream.h \
  $$PWD/include/fmt/printf.h \
  $$PWD/include/fmt/ranges.h \
  $$PWD/include/fmt/xchar.h

DEFINES += FMT_HEADER_ONLY
