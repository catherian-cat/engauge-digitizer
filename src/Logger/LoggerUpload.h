#ifndef LOGGER_UPLOAD_H
#define LOGGER_UPLOAD_H

/// Upload logging information to website for developer support
class LoggerUpload
{
public:
  /// Single constructor
  LoggerUpload();

  static void assert(bool condition,
                     const char* file,
                     int line);
};

#endif // LOGGER_UPLOAD_H
