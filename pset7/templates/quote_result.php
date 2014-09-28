    <table class="table table-striped">
      <thead>
        <tr>
          <td>Symbol</td>
          <td>Name</td>
          <td>Price</td>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td><?= $symbol ?></td>
          <td><?= $name ?></td>
          <td><?= "$" . number_format($price, 2) ?></td>
        <tr>
      </tbody
    </table>    
    <p>
        <a href="javascript:history.go(-1);">Back</a>
    </p> 
