#ifndef FLNC_H
#define FLNC_H

#include <vector>
typedef std::basic_istream<char,std::char_traits<char>> minput_stream;
typedef std::basic_ostream<char,std::char_traits<char>> moutput_stream;

namespace flnc
{
	
	/*!
	 * Writes a vector to file. The format is:
	 * \code
	 * vector_size vector_1st_element vector_2nd_element ...
	 * \endcode
	 *
	 * @param TrainingFileOut the output stream of the file to write the vector to.
	 * @param vec the vector to be written to file.
	 */
	template<typename TYPE> void WriteVectorToFile(moutput_stream *TrainingFileOut, const std::vector<TYPE>& vec){
		(*TrainingFileOut) << vec.size() << " ";
		for (int j = 0; j < vec.size(); j++)
			(*TrainingFileOut) << (vec[j] < 0.000000001f ? 0 : vec[j]) << " ";
		(*TrainingFileOut) << "\n";	
	};

	/*!
	 * Writes a vector of vectors to file. The format is:
	 * \code
	 * number_of_vectors
	 * vector_size vector_1st_element vector_2nd_element ...
	 * vector_size vector_1st_element vector_2nd_element ...
	 *     ...            ...                ...         ...
	 * \endcode
	 * 
	 * @param TrainingFileOut the output stream of the file to write the vector to.
	 * @param vec the vector of vectors to be written to file.
	 */
	template<typename TYPE> void Write2DVectorToFile(moutput_stream *TrainingFileOut, const std::vector< std::vector<TYPE> >& vec){
		(*TrainingFileOut) << vec.size();
		(*TrainingFileOut) << "\n";
		for (int i = 0; i < vec.size(); i++)
			WriteVectorToFile(TrainingFileOut, vec[i]);
	};

	/*!
	 * Reads a vector from file. The format of the file must be
	 * \code
	 * vector_size vector_1st_element vector_2nd_element ...
	 * \endcode
	 * 
	 * @param TrainingFileIn the input stream of the file to read the vector from.
	 * @param vec the vector to be read to file.
	 */
	template<typename TYPE> void ReadVectorFromFile(minput_stream *TrainingFileIn, std::vector<TYPE>& vec){
		int vecSize;
		(*TrainingFileIn) >> vecSize;
		vec.resize(vecSize);
		for (int j = 0; j < vecSize; j++)
			(*TrainingFileIn) >> vec[j];
	}

	/*!
	 * Reads a vector of vectors to file. The format of the file must be
	 * \code
	 * number_of_vectors
	 * vector_size vector_1st_element vector_2nd_element ...
	 * vector_size vector_1st_element vector_2nd_element ...
	 *     ...            ...                ...         ...
	 * \endcode
	 * 
	 * @param TrainingFileIn the input stream of the file to read the vector from.
	 * @param vec the vector of vectors to be read to file.
	 */
	template<typename TYPE> void Read2DVectorFromFile(minput_stream *TrainingFileIn, std::vector< std::vector<TYPE> >& vec){
		int vecSize;
		(*TrainingFileIn) >> vecSize;
		vec.resize(vecSize);
		for (int i = 0; i < vecSize; i++)
			ReadVectorFromFile(TrainingFileIn, vec[i]);
	}
}

#endif	// FLNC_H