#
# Adrian Statescu <mergesortv@gmail.com>
# Computes COS(x) using Taylor Series
# 
# cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
#
#

def fact n

    if n == 0

       return 1

    else

       return n * fact( n  - 1)

    end
end

def pow(a,b)

    p = 1

    b.times do

        p *= a

    end

    p.to_f
end

def cos x

    anEPS = 0.0001

    term1 = 1
 
    term2 = term1 - pow(x,2) / fact(2)

    i = 2

    loop do          

        term1 = term2

        term2 += pow(-1,i) * (pow(x, (2 * i)) / fact(2 * i)).to_f

        i = i + 1

        break if (term1 > term2 ? term1 - term2 : term2 - term1) <= anEPS
    end

    term2
end

p cos(-1.5)
p Math.cos(-1.5)
