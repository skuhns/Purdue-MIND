package purduecom.sam.mind_app;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;

public class exercise_Activity extends AppCompatActivity {

    //GLOBAL arrays for storing information

    int[] realStream = new int[1000];
    char[] rawStream = new char[2001];

    @Override
    //This block of code gets ran whenever this activity is called by a button or whatever
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_exercise_);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


        beginRead(realStream, rawStream);

        //TODO Add support for device and reading in data
    }
    
    //TODO This function should begin the input stream from the device to the phone
    //TODO for now, feel free to use dummy data for now to get the functions connected
    public static void beginRead(int[] realStream, char[] rawStream) {
        int flag = 0;

        //TODO get data from device and fill array every (realStream.length / 20) seconds



        //TODO after data is put in realStream using parseData, interpret it!
        flag = interpret(parseData(realStream,rawStream));

        //TODO create multiple text view representing actions we support and set specific one to visible based on flag
        switch (flag) {
            //TODO replace prints with displaying stuff in app
            case 0: //nothing is done
                System.out.println("nothing");
                break;
            case 1:
                System.out.println("finger wiggle or some shit");
                break;
            //ETC
        }
    }


    public static int interpret(int[] realStream) {
        //after interpretation, flag should be set to an int corresponding with action
        int flag=0;
        //TODO interpret data into decisive actions (grip, move finger, etc)

        return flag;
    }

    //converts the raw stream
    public static int[] parseData(int[] realStream, char[] rawStream){
        //
        for (int i = 0; i < rawStream.length; i++) {
            //43 is ascii value for '+' which seperates ints inside raw stream
            if(i%2 == 0 && rawStream[i] != 43) {
                realStream[i/2] = rawStream[i];
            }
        }
        return realStream;
    }

}
