  DOMhelp = {

       addEvent: function(elem,evType,fn,useCapture){

                 if(elem.addEventListener) {

                         elem.addEventListener(evType,fn,useCapture);

                 } else if(elem.attachEvent) {

                         var r = elem.attachEvent('on'+evType,fn);

                         return r;                          

                 } else {

                        elem['on'+evType] = fn; 
                 }
       }

  };

    //cos(x) = 1-x^2/2!+x^4/4!-x^6/6!+..-

    function factorial(n) {
             if(n==1 || n==0) return 1;
                else return n*factorial(n-1);
    }

    function pow(x,y) {
        var p = 1;
        for(var i=1;i<=y;i++) {
            p *= x 
        }  
      return parseFloat(p)
    }

    function abs(x,y) {
         if(x>y) {
            return x-y
         } else {
            return y-x
         }
    } 

    function cos(x) {

         var eps = 0.0001;

         var n = 2, 
             v1 = 1,
             v2 = v1 - pow(x,2)*1.0/factorial(2);

         while(abs(v1,v2) >= eps) {

               v1 = v2;
               v2 += pow(-1,n)*pow(x,2*n)*1.0/factorial(2*n)               
               n++;  
         } 

       return v2;
    }

    var solve = function() {
       
        var input = parseFloat(document.getElementById('input').value);  
 
        if(!input) {document.getElementById('solution').innerHTML = "error!";return;}

        var output = "Math.cos(x) = " + Math.cos(input) + '<br\>' + "cos(x)=" + cos(input)

        document.getElementById('solution').innerHTML = output;
    }

    var init = function() {

        DOMhelp.addEvent(document.getElementById('solve'),'click',solve,false); 
    }; 

    DOMhelp.addEvent(window,'load',init,false);
