#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<set>
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
                    bookNo(book), price(sales_price){}
    std::string ISBN() const {return bookNo;}
    virtual double net_price(std::size_t n) const
            { return n * price;}
    virtual std::ostream& debug(std::ostream &os)const {
        os << "Quote:bookNO: " << bookNo << "Quote:price: "  << price;
        return os;
    }
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
    virtual ~Quote() = default; 
protected:
    double price = 0.0;
private:
    std::string bookNo;
};
class Disc_quote: public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double p, std::size_t qty, double disc):
        Quote(book,p), quantity(qty), discount(disc){} 
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
class Bulk_quote : public Disc_quote{
public:
    // Bulk_quote() = default;
    using Disc_quote::Disc_quote;
    //Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
    //    Disc_quote(book,p,qty,disc) {}
    Bulk_quote * clone() const & {return new Bulk_quote(*this);}
    Bulk_quote * clone() && {return new Bulk_quote(std::move(*this));}
    double net_price(std::size_t) const override;
    std::ostream& debug(std::ostream &os) const override{
        Quote::debug(os) << " Bulk_quote:min_qty: "<< Bulk_quote::min_qty << " Bulk_quote discount: "  << discount;
        return os;
    }
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};
double print_total(std::ostream &os, const Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.ISBN() << "# sold:" << n << " total due:" << ret << std::endl;
    return ret;
}
double Bulk_quote::net_price(size_t cnt) const{
    if (cnt >= quantity){
        return cnt * (1 - discount) * price;
    }
    else
        return cnt * price;
}
class Basket{
public:
    void add_item(const std::shared_ptr<Quote> &sale){items.insert(sale);}
    void add_item(const Quote &sale){items.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote && sale){items.insert(std::shared_ptr<Quote>(std::move(sale.clone())));}
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote>&lhs,const std::shared_ptr<Quote>&rhs){return lhs->ISBN() < rhs->ISBN();};
    std::multiset<std::shared_ptr<Quote>,decltype(compare)*>items{compare};
};
double Basket::total_receipt(std::ostream&os) const{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
       sum += print_total(os,**iter,items.count(*iter));
    }
    os << "Total Sale:" << sum << std::endl;
    return sum;
}
int main(){
    std::vector<std::shared_ptr<Quote>> basket;
    Quote basic("abc",5.5);
    Bulk_quote bulk("abc",5.5,10,0.2);
    Basket bsk;
    bsk.add_item(std::make_shared<Quote>("123",45));
    bsk.add_item(std::make_shared<Bulk_quote>("456",45,3,.15));
    print_total(std::cout,basic,20);
    print_total(std::cout,bulk,20);
    basic.debug(std::cout)<<std::endl;
    bulk.debug(std::cout)<<std::endl;
    return 0;
}