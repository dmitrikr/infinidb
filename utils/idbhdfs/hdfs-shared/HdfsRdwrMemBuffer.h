/* Copyright (C) 2013 Calpont Corp.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation;
   version 2.1 of the License.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA. */

#ifndef HDFSRDWRMEMBUFFER_H_
#define HDFSRDWRMEMBUFFER_H_

#include <stdexcept>
#include <boost/utility.hpp>
#include "hdfs.h"
#include "IDBDataFile.h"


namespace idbdatafile
{
class HdfsRdwrFileBuffer;

/**
 * HdfsRdwrMemBuffer implements IDBDataFile for a file in the Hadoop file system
 * (HDFS).  This file type is special in that it allows random access to a
 * file open for writing - this is not typically allowed by HDFS.  It does
 * this by maintaining an internal buffer.  All operations occur in memory
 * until the final write to disk upon close().
 */
class HdfsRdwrMemBuffer: public IDBDataFile, boost::noncopyable
{
public:
	HdfsRdwrMemBuffer(const char* fname, const char* mode, unsigned opts, unsigned defsize);
	/* virtual */ ~HdfsRdwrMemBuffer();

	/* virtual */ ssize_t pread(void *ptr, off64_t offset, size_t count);
	/* virtual */ ssize_t read(void *ptr, size_t count);
	/* virtual */ ssize_t write(const void *ptr, size_t count);
	/* virtual */ int seek(off64_t offset, int whence);
	/* virtual */ int truncate(off64_t length);
	/* virtual */ off64_t size();
	/* virtual */ off64_t tell();
	/* virtual */ int flush();
	/* virtual */ time_t mtime();

    // Returns the total size of all currently allocated HdfsRdwrMemBuffers
    static size_t getTotalBuff() {return t_totalbuff;}

    // This is used by HdfsRdwrFileBuffer constructor to dump our buffer 
    // contents to a file when we run out of memory
    const unsigned char* getbuffer() const {return m_buffer;}
    off64_t getSize() {return m_size;} // TODO: remove after debug
protected:
	/* virtual */ void close();

private:
	void allocBuffer(size_t size);
	void releaseBuffer();
	int flushImpl();

	uint8_t*  m_buffer;
	off64_t   m_cur;
	off64_t   m_last;
	off64_t   m_size;
	bool      m_dirty;
	bool      m_new;
	bool      m_noflush;

	static int64_t  t_totalbuff;

    HdfsRdwrFileBuffer* m_pFileBuffer;
};

}

#endif /* HDFSRDWRMEMBUFFER_H_ */
