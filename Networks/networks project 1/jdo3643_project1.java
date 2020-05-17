// Jerry Olds
// 1001533643
// CSE-4344-001
// Project 1

// REFERENCE: https://www.net.t-labs.tu-berlin.de/teaching/computer_networking/ap01.htm

import java.io.*;
import java.net.*;
import java.util.*;

/**
 *
 * @author Jerry Olds
 */

public class jdo3643_project1 
{
    public static void main(String [] args) throws Exception
    {
        // Port number
        int port_num = 6789;
        
        // Create listener socket
        try(ServerSocket listener = new ServerSocket(port_num))
        {
            // Process requests
            while(true)
            {
                // Create new request and thread
                Socket connection = listener.accept();
                HttpRequest request = new HttpRequest(connection);
                Thread thread = new Thread(request);
                thread.start();
            }
        }
        
     
    }
}

final class HttpRequest implements Runnable
{
    final static String CRLF = "\r\n";
    Socket socket;
    
    // Constructor
    public HttpRequest(Socket socket) throws Exception
    {
        this.socket = socket;
    }
    
    // Calls processRequest() method
    @Override
    public void run()
    {
        try
        {
            processRequest();
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }
    
    // All of program processing occurs in this function
    // Checks to see if file can be found and outputs
    // Sends data to output function
    private void processRequest() throws Exception
    {
        // Readers
        InputStreamReader isr = new InputStreamReader(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        BufferedReader reader = new BufferedReader(isr);
        
        // Get content of request
        System.out.println();
        System.out.println("***************NEW REQUEST***************");
        String content = reader.readLine();
        
        // Get file name
        StringTokenizer token = new StringTokenizer(content);
        String method = token.nextToken();
        String fileName = token.nextToken();
        fileName = "." + fileName;
        
        // Open file
        FileInputStream fis = null;
        boolean fileExists = true;
        try
        {
            fis = new FileInputStream(fileName);
            
        }
        catch(FileNotFoundException e)
        {
            fileExists = false;
        }
        
        // Define header variables
        String statusLine = null;
        String contentTypeLine = null;
        String entityBody = null;
		
        // If file exists, set header information
        if(fileExists)
        {
			
            statusLine = "200 OK";
            contentTypeLine = "Content-type: " + contentType(fileName) + CRLF;
        }
        // If file does not exist, set header information
        else
        {
            statusLine = "404 Not Found\n";
            contentTypeLine = "Content-type: " + contentType(fileName) + CRLF;
            entityBody = "<HTML>" + "<HEAD><TITLE>Not Found</TITLE></HEAD>" + "<BODY>Not Found</BODY></HTML>";
        }
        
        // Output information if file exists
        if(fileExists)
        {
			dos.writeBytes("HTTP/1.1 200 OK");
		    dos.writeBytes(contentTypeLine);
		    dos.writeBytes(CRLF);
			System.out.println(statusLine);
			System.out.print(contentTypeLine);
			System.out.print(CRLF);
            sendBytes(fis, dos);
            fis.close();
        }

        // Output information if file does not exists
        else
        {
            dos.writeBytes("HTTP/1.1 404 Not Found");
            dos.writeBytes(contentTypeLine);
		    dos.writeBytes(CRLF);
            dos.writeBytes(entityBody);
            System.out.println(statusLine);
			System.out.print(contentTypeLine);
			System.out.print(CRLF);
            sendBytes(fis, dos);
            fis.close();
        }
        
        // Display the content of request
        while((content = reader.readLine()).length() != 0)
		{
			System.out.println(content);
		}
        
        // Close objects
        reader.close();
        socket.close();
    }
    
    // Looks at file extension and returns type of content
    private static String contentType(String fileName)
    {
        if(fileName.endsWith(".htm") || fileName.endsWith(".html"))
        {
            return "text/html";
        }
        if(fileName.endsWith(".jpg"))
        {
            return "image/jpg";
        }
        if(fileName.endsWith(".png"))
        {
            return "image/png";
        }
        if(fileName.endsWith(".gif"))
        {
            return "image/gif";
        }
        return "application/octet-stream";
    }
    
    // Outputs file information
    private static void sendBytes(FileInputStream fis, OutputStream os) throws Exception
    {
        // Buffer
        byte[] buffer = new byte[1024];
        int bytes = 0;
        
        // Write data from input stream
        while((bytes = fis.read(buffer)) != -1)
        {
            os.write(buffer, 0, bytes);
        }
		os.close();
    }

}



