#ifndef PJC_PROJECT_IMAGE_FILE_H
#define PJC_PROJECT_IMAGE_FILE_H

#include <string>
#include <fstream>
#include <utility>

namespace filetypes {

    /**
     * Abstract class for image file and interacting with it
     */
    class image_file
    {
    protected:
        const std::string_view filename;

        /**
         * Copy current file to the destination
         * @param destination Path to the file where to copy
         * @return Opened std::ofstream to the destination
         * @throw read_error Thrown if file or destination could not be opened or read;
         */
        std::ofstream copy_file(const std::string_view &destination) const;

    public:
        image_file(const std::string_view &filename);
        image_file(const image_file&) = delete;
        image_file(image_file&&) = delete;

        /**
         * Read the file with name 'filename' that was passed in constructor
         * @throw read_error Thrown if file cannot be read
         */
        virtual void read() = 0;

        /**
         * Check if message could be injected into file
         * @param message Message to check
         * @return true or false
         * @throw std::runtime_error Thrown if file was not read beforehand
         */
        virtual bool check(const std::string_view &message) const = 0;

        /**
         * Try injecting message into file
         * @param message Message to inject
         * @throw std::runtime_error Thrown if file was not read beforehand
         * @throw injection_error Thrown if message could not be injected
         */
        virtual void inject(const std::string_view &message) = 0;

         /**
          * Try extracting message from file
          * @return message that was extracted
          * @throw std::runtime_error Thrown if file was not read beforehand
          */
         virtual std::string extract() const = 0;

         /**
          * Write file into destination
          * @param destination Filename where to write
          * @throw std::runtime_error Thrown if file was not read beforehand
          * @throw read_error Thrown if file cannot be read or written
          */
         virtual void write(const std::string_view& destination) const = 0;

         /**
          * Get image dimensions
          * @return Pair of width and height of image
          */
         virtual std::pair<size_t, size_t> dimensions() const = 0;
    };

}

#endif