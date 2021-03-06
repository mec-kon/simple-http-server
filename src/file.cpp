#include "file.h"

/**
 * @brief method to get the file name with file extension
 *
 * This method returns the file name with an extension for a
 * string,in which an HTTP request is stored.
 *
 * @param request (The HTTP request.)
 * @return filename (The filename with extension as string.)
 */
string file::get_filename(string request) {
    string filename;
    char delim = ' ';

    request.erase(0, request.find(delim) + 1);
    filename = request.substr(0, request.find(delim));

    //remove first char
    filename.erase(0, 1);

    if (filename == "") {
        filename = "index.html";
    }

    return filename;
}

/**
 * @brief method to get the file extension without file name.
 *
 * This method returns the file extension without a file name for a
 * string in which the file name with the extension is stored.
 *
 * @param filename (The file name with extension as string.)
 * @return filename (The file extension without file name as string.)
 */
string file::get_file_ending(string filename) {
    char delim = '.';
    filename.erase(0, filename.find(delim) + 1);
    return filename;
}

/**
 * @brief this method checks whether a file exists
 *
 * @param filename (File name to be checked.)
 * @return file_f (A boolean variable that specifies whether the file exists or not.)
 */
bool file::file_exists(string filename) {
    ifstream file_f(filename.c_str());
    return (bool) file_f;
}

/**
 * @brief method to open file as a string
 *
 * This method opens a file and returns its contents as a string.
 *
 * @param filename (Name of the given file.)
 * @return data (Content of the file as string, if it exists. Otherwise "file not found".)
 */
string file::open_file(string filename) {

    if (filename == "") {
        filename = "index.html";
    }

    if (file_exists(STATIC_PATH + filename)) {
        string data;
        ifstream infile;
        string path = STATIC_PATH + filename;
        infile.open(path.c_str());

        data.assign((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));

        infile.close();
        return data;
    }
    else {
        return "file not found";
    }


}

/**
 * @brief method to write a string to a file
 *
 * This method saves a string in a file.
 *
 * @param filename
 * @param content
 * @return data
 */
string file::write_file(string filename, string content) {

    string data;

    if (filename == "") {
        filename = "index.html";
    }
    if (file_exists(FILES_PATH + filename))
        data = "Added to existing file";
    else
        data = "Created new file";

    ofstream outfile;
    outfile.open(FILES_PATH + filename);
    outfile << content;
    outfile.close();

    return data;
}