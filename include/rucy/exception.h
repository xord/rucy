// -*- c++ -*-
#pragma once
#ifndef __RUCY_EXCEPTION_H__
#define __RUCY_EXCEPTION_H__


#include <stdexcept>
#include <xot/exception.h>
#include <rucy/value.h>


namespace Rucy
{


	class RubyException : public std::runtime_error
	{

		typedef std::runtime_error Super;

		public:

			RubyException (Value exception);

			RubyException (Value exception, const char* format, ...);

			const char* what () const throw();

			Value value () const;

		private:

			/*Global*/Value val;

	};// RubyException


	struct RubyJumpTag
	{

		public:

			int tag;

			RubyJumpTag (int tag);

	};// RubyJumpTag


	void raise (const char* format = NULL, ...);

	void raise (RubyValue exception, const char* format = NULL, ...);


	void rucy_error            (const char* file, int line, const char* format = NULL, ...);

	void type_error            (const char* file, int line, const char* format = NULL, ...);

	void argument_error        (const char* file, int line, const char* format = NULL, ...);

	void arg_count_error       (const char* file, int line,
		const char* method, int nargs, int nargs_expected,
		int n1 = -1, int n2 = -1, int n3 = -1, int n4 = -1, int n5 = -1,
		int n6 = -1, int n7 = -1, int n8 = -1, int n9 = -1, int n10 = -1);

	void invalid_state_error   (const char* file, int line, const char* format = NULL, ...);

	void invalid_object_error  (const char* file, int line, const char* format = NULL, ...);

	void index_error           (const char* file, int line, const char* format = NULL, ...);

	void not_implemented_error (const char* file, int line, const char* format = NULL, ...);

	void system_error          (const char* file, int line, const char* format = NULL, ...);


	typedef bool (*RubyExceptionHandler) (const RubyException& e);

	void                 set_exception_handler (RubyExceptionHandler handler);

	RubyExceptionHandler get_exception_handler ();


}// Rucy


#endif//EOH
