#ifndef PJC_PROJECT_FILE_CONTEXT_H
#define PJC_PROJECT_FILE_CONTEXT_H

#include <memory>
#include <string_view>
#include <concepts>

#include "../filetypes/image_file/image_file.h"

/**
 * File context for image files that uses RAII programming technique and delegates all calls of check, inject, extract to the filetype
 * @tparam filetype Class derived from image_file that implements certain image file type
 */
template<typename filetype>
requires std::derived_from<filetype, filetypes::image_file>
class file_context {
private:
    std::unique_ptr<filetypes::image_file> file;
    const std::string_view &destination;
    bool changed;

public:
    file_context(const std::string_view &filename)
        : file{std::make_unique<filetype>(filename)}
        , destination{filename}
        , changed{false}
    {
        file->read();
    }

    file_context(const std::string_view &filename, const std::string_view &destination)
        : file{std::make_unique<filetype>(filename)}
        , destination{destination}
        , changed{false}
    {
        file->read();
        file->write(destination);
    }

    ~file_context()
    {
        if(changed)
            file->write(destination);
    }

    bool check(const std::string_view &message) const { return file->check(message); }

    void inject(const std::string_view &message)
    {
        file->inject(message);
        changed = true;
    }

    std::string extract() const { return file->extract(); }
};

#endif